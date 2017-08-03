import java.util.*;

public class Karatsuba {
	public static void main(String[] args) {
		if (args.length != 2){
			System.err.println("Incorrect number of arguments.\n");
			System.exit(-1);
		}
		int size1 = args[0].length();
		int size2 = args[1].length();
		if (size1 != size2) {
			System.err.println("Inputs must be two n-digit integers\n");
			System.exit(-1);
		}

		int[] n1 = new int[size1];
		int[] n2 = new int[size2];
		int[] ans;
		int j = 0;

		for (int i = size1-1; i >= 0; i--){
			n1[j] = args[0].charAt(i) - 48;
			n2[j] = args[1].charAt(i) - 48;
			j++;
		}

		ans = karatsuba(n1,n2);
		printNum(ans, ans.length);
	}

	public static int[] karatsuba(int[] n1, int[] n2) {
		int length1 = n1.length, length2 = n2.length;
		int[] ans = new int[2 * Math.max(length1,length2)];

		if (length1 != length2) {
			if (length1 < length2) {
				n1 = Arrays.copyOf(n1,n2.length);
			} else {
				n2 = Arrays.copyOf(n2,n1.length);
			}
		}
		int length = n1.length;
		if (length == 1) {
			if (n1[0]*n2[0] > 9) {
				ans[0] = n1[0]*n2[0] % 10;
				ans[1] = n1[0]*n2[0] / 10;
			} else {
				ans[0] = n1[0]*n2[0];
			}
			return ans;
		}

		int middle = length/2 + length%2;
		int[] a = new int[length-middle];
		int[] b = new int[middle];
		int[] c = new int[length-middle];
		int[] d = new int[middle];

		for (int i = 0; i < a.length; i++) {
			a[i] = n1[i];
			c[i] = n2[i];
		}
		for (int j = 0; j < b.length; j++) {
			if (length % 2 != 0) {
				b[j] = n1[j+middle-1];
				d[j] = n2[j+middle-1];
			} else {
				b[j] = n1[j+middle];
				d[j] = n2[j+middle];

			}
		}

		int[] x = karatsuba(b,d);
		int[] y = karatsuba(a,c);
		int[] z = karatsuba(add(a,b),add(c,d));
		z = subtract(z,y);
		z = subtract(z,x);

		int exp, mid_exp;
		if (length % 2 != 0) {
			exp = length - 1;
		} else {
			exp = length;
		}
		mid_exp = exp/2;
		int[] ans_1 = new int[exp + x.length];
		int[] ans_2 = new int[mid_exp + z.length];
		for (int i = 0, j = exp; i < ans_1.length; i++) {
			if (j > 0) {
				j--;
				continue;
			}
			ans_1[i] = x[i-exp];
		}

		for (int i = 0, j = mid_exp; i < ans_2.length; i++) {
			if (j > 0) {
				j--;
				continue;
			}
			ans_2[i] = z[i-mid_exp];
		}

		return add(add(ans_1,ans_2),y);
	}

	public static int[] subtract(int[] n1, int[] n2) {
		int[] ans = new int[Math.max(n1.length,n2.length)];
		if (n1.length != n2.length) {
			if (n1.length < n2.length) {
				n1 = Arrays.copyOf(n1,n2.length);
			} else {
				n2 = Arrays.copyOf(n2,n1.length);
			}
		}
		for (int i = 0; i < n1.length; i++) {
			if (n1[i]-n2[i] < 0) {
				n1[i] += 10;
				if (i == n1.length - 1) continue;
				n1[i+1] -= 1;
			}
			ans[i] = n1[i]-n2[i];
		}

		return ans;
	}

	public static int[] add(int[] n1, int[] n2) {
		int[] ans = new int[Math.max(n1.length,n2.length) + 1];
		if (n1.length != n2.length) {
			if (n1.length < n2.length) {
				n1 = Arrays.copyOf(n1,n2.length);
			} else {
				n2 = Arrays.copyOf(n2,n1.length);
			}
		}
		for (int i = 0; i < n1.length; i++) {
			if (n1[i]+n2[i] > 9) {
				n1[i] -= 10;
				if (i != n1.length - 1) {
					n1[i+1] += 1;
				} else {
					ans[i+1] += 1;
				}
 			}
			ans[i] = n1[i]+n2[i];
		}
		if (ans[ans.length - 1] == 0) {
			int[] ans2 = new int[ans.length - 1];
			for (int i = 0; i < ans2.length; i++) {
				ans2[i] = ans[i];
			}
			return ans2;
		}
		return ans;
	}

	public static void printNum(int[] n1, int size) {
		for (int i = size-1; i >= 0; i--) {
			if (n1[i] == 0 && i >= size-2) continue;
			System.out.printf("%d", n1[i]);
		}
		System.out.print("\n");
		return;
	}

}

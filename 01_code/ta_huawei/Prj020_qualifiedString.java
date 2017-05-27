package prj020_qualifiedString;

import java.util.Scanner;

public class Prj020_qualifiedString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String str = in.nextLine();
			if (isLenghOK(str) && isRepeatOK(str) && isMultiType(str)) {
				System.out.println("OK");
			} else {
				System.out.println("NG");
			}
		}
		in.close();
	}
	
	private static boolean isLenghOK(String str) {
		int len = str.length();
		if (len > 8) {
			return true;
		} else {
			return false;
		}
	}
	
	private static boolean isRepeatOK(String str) {
		int len = str.length();
		int[][] dp = new int[len][len];
		int maxRepeatLen = 0;
		
		for(int m=1; m<len; m++) {
			for(int n=m; n<len; n++) {
				if (m!=n && str.charAt(m)==str.charAt(n)) {
					dp[m][n] = dp[m-1][n-1] + 1;
				}
				
				maxRepeatLen = Math.max(dp[m][n], maxRepeatLen);
				if (maxRepeatLen > 2) {
					return false;
				}
			}
		}
		return true;
	}
	
	private static boolean isMultiType(String str) {
		int len = str.length();
		char c; int containTypes = 0;
		boolean isDigit = false, isLower = false;
		boolean isUpper = false, isOther = false;
		for(int i=0; i<len; i++) {
			c = str.charAt(i);
			if (c>='0' && c<='9') {
				containTypes = isDigit ? containTypes : containTypes+1;
				isDigit = true;
			} else if (c>='a' && c<='z') {
				containTypes = isLower ? containTypes : containTypes+1;
				isLower = true;
			} else if (c>='A' && c<='Z') {
				containTypes = isUpper ? containTypes : containTypes+1;
				isUpper = true;
			} else {
				containTypes = isOther ? containTypes : containTypes+1;
				isOther = true;
			}
			
			if (containTypes >= 3) {
				return true;
			}
		}
		return false;
	}

}

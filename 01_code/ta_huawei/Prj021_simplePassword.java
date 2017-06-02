package prj021_simplePassword;

import java.util.Scanner;

public class Prj021_simplePassword {
	public static void main(String[] argv) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			String str = in.nextLine();
			int length = str.length();
			StringBuffer rlt = new StringBuffer();
			char ch;
			for(int i=0; i<length; i++) {
				ch = str.charAt(i);
				if (ch >= 'a' && ch <= 'z') {
					rlt.append(cvtLowerCase(ch));
				} else if (ch >= 'A' && ch <= 'Z') {
					rlt.append(cvtUpperCase(ch));
				} else {
					rlt.append(ch);
				}
			}
			System.out.println(rlt);
		}
	}
	
	private static char cvtUpperCase(char ch) {
		int rlt = Integer.valueOf(ch) + 33;
		if (rlt > Integer.valueOf('z')) return 'a';
		return (char)rlt;		
	}
	
	private static int cvtLowerCase(char ch) {
		if (ch == 'z') return 9;
		if (ch >= 's') ch--;
		int rlt = 2 + (Integer.valueOf(ch)-97)/3;
		return rlt;
	}
}

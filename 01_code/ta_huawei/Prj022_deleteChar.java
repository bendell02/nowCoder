package prj022_deleteChar;

import java.util.HashMap;
import java.util.Scanner;

public class Prj022_deleteChar {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			HashMap<Character, Integer> frequency = new HashMap<Character, Integer>();
			String str = in.nextLine();
			int len = str.length();
			char ch; int tempF, minF = 21;
			for(int i=0; i<len; i++) {
				ch = str.charAt(i);
				if (frequency.containsKey(ch)) {
					tempF = frequency.get(ch) + 1;
				} else {
					tempF = 1;
				}
				frequency.put(ch, tempF);
				if (minF > tempF) {
					minF = tempF;
				}
			}
			StringBuffer rlt = new StringBuffer();
			for(int i=0; i<len; i++) {
				ch = str.charAt(i);
				if(frequency.get(ch) != minF) {
					rlt.append(ch);
				}
			}
			System.out.println(rlt.toString());
		}
		in.close();		
	}

}

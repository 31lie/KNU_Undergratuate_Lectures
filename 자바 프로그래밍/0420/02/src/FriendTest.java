// 2020114658 이윤서

import java.util.Scanner;

class Friend {
	
	String name;
	int age;
	
	public Friend(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String printFriend() {
		return String.format("%s %d", name,age);
	}
}


public class FriendTest {
	
	public static void inputData(Friend[][][] array) {
		
		System.out.println("input (name age)");
		Scanner input = new Scanner(System.in);
		
		String dataName; int dataAge;
		
		for (int i=0; i < array.length ;i++) {
			for (int j=0; j < array[i].length;j++) {
				for (int k=0; k<array[i][j].length;k++) {
					dataName = input.next();
					dataAge = input.nextInt();
					array[i][j][k] = new Friend(dataName,dataAge);
				}
			}
		}
		
		input.close();
	}
	
	public static void printData(Friend[][][] array) {
		
		for (Friend[][] section: array) {
			for (Friend[] row : section) {
				for (Friend col : row) {
					System.out.println(col.printFriend());
				}
			}
			System.out.println();
		}
	}
	

	public static void main(String[] args) {
		
		
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("3차원 배열의 sections, rows, cols: ");
		int sect = sc.nextInt();
		int rows = sc.nextInt();
		int cols = sc.nextInt();
		
		
		
		Friend[][][] myFriends= new Friend[sect][rows][cols];
		inputData(myFriends);
		printData(myFriends);
		
		sc.close();
		
		
		
	}

}

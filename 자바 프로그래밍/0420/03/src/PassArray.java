// 2020114658 이윤서

import java.util.Scanner;
import java.util.Arrays;
import java.security.SecureRandom;



public class PassArray {
	
	public static void inputArray3D (int[][][] array) {	
			int num;
			SecureRandom random = new SecureRandom();
			
			for (int i=0; i < array.length ;i++) {
				for (int j=0; j < array[i].length;j++) {
					for (int k=0; k<array[i][j].length;k++) {
						
						num = random.nextInt(10)+1;
						array[i][j][k] = num;
					}
				}
			}
			
			
		}
	
	
	public static void printArray3D(int[][][] array) {
			
			for (int[][] section: array) {
				for (int[] row : section) {
					for (int num : row) {
						System.out.printf("%5d", num);
					}
					System.out.println();
				}
				System.out.println();
			}
		}
	
	
	public static void arraysort(int[][][] array) {
		
		for (int i=0; i < array.length ;i++) {
			for (int j=0; j < array[i].length;j++) {
				Arrays.sort(array[i][j]);
			}
		}
	}
	
	

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		System.out.println("3차원 배열의 sections, row, cols: ");
		int sections = input.nextInt();
		int rows = input.nextInt();
		int cols = input.nextInt();
		
		int[][][] array = new int[sections][rows][cols];
		
		inputArray3D(array);
		System.out.println("after creating random numbers");
		printArray3D(array);
		arraysort(array);
		System.out.println("after sorting");
		printArray3D(array);
		

	}

}

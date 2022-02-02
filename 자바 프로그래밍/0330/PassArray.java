//2020114658 이윤서
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.


public class PassArray {

	public static void main(String args[]) {
		
		int[][] array = {{1,2,3},{4,5},{6,7,8,9}};
		
		printArray2D1(array); //(1)
		printArray2D2(array); //(2)
	}
	
	public static void printArray2D1(int[][] arr) //(3)
	{
		//(4) counter controlled for statement
		for (int row=0; row<arr.length;row++) {
			for (int col=0 ; col<arr[row].length;col++) {
				System.out.printf("%2d", arr[row][col]);
			}
			System.out.println();
		}
	}
	
	public static void printArray2D2(int[][] arr)  //(5)
	{
		//(6) enhanced for statement
		for (int row[] : arr ) {
			for (int num : row) {
				System.out.printf("%2d",num);
			}
			System.out.println();
		}
	}
}

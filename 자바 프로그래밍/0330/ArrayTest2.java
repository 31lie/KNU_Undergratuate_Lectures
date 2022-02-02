//2020114658 이윤서
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.


public class ArrayTest2 {

	public static void main(String[] args) {
		//(1) 2차원 배열 선언, new 연산자 사용, 4문장
		int[][] arr = new int[3][];
		arr[0] = new int[2];
		arr[1] = new int[1];
		arr[2] = new int[3];
		
		//(2) 모든 배열 원소에  할당, counter controlled for statement
		for (int row=0;row<arr.length;row++) {
			for (int col=0;col<arr[row].length;col++) {
				arr[row][col]=1;
			}
		}
		
		//(3) 배열 원소의 값을 그림과 같은 모양으로 출력, enhanced for statement
		for (int row[] : arr ) {
			for (int num : row) {
				System.out.printf("%2d", num);
			}
			System.out.println();
		}
	}

}

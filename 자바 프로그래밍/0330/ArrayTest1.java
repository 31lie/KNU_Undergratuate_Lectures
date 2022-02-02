//2020114658 이윤서
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.


public class ArrayTest1 {
	
	//(1) counter controlled for statement
	
	public static int sumArray1D1(int[] arr) {
		int sum=0;	
		for (int counter =0; counter < arr.length;counter++) {
			sum = sum + arr[counter];
		}
		return sum;
	}
	
	// (2) enhanced for statement
	
	public static int sumArray1D2(int[] arr) {
		int sum=0;
		for(int num: arr) {
			sum = sum + num;
		}
		return sum;
	}

	public static void main(String[] args) {
		int[] array = {10,20,30,40};
		
		System.out.printf("SumArray1D1 : %d, sumArray1D2 : %d\n", sumArray1D1(array), sumArray1D2(array));

	}

}

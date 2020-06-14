package first;
import java.lang.Math;
import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Введите длинну массива: ");
		int N = in.nextInt();
		double[] X = new double[N];
		System.out.println("Введите элементы массива:");
		for (int i = 0; i < N; i++) {
			System.out.print("X" + i + ": ");
			X[i] =  in.nextDouble();
		}
		in.close();
		double minEven=0;
		for(int iterator=0;iterator<N;iterator++) {
			if(Math.abs(X[iterator])%2.0==0.0) {
				minEven=X[iterator];
				break;
			}
		}
		int counterOdd=0;
		for (int iterator=0;iterator<N;iterator++) {
			if(Math.abs(X[iterator])%1.0!=0.0) counterOdd++;
			if((Math.abs(X[iterator])%2.0==0.0)&&(X[iterator]<minEven)) minEven = X[iterator];
		}
		if(counterOdd!=0) {
			double[] lessArray = new double[counterOdd];
			int lengthCounter =0;
			for(int iterator=0;iterator<X.length;iterator++) {
				if(Math.abs(X[iterator])%1.0!=0.0) {
					lessArray[lengthCounter]=X[iterator];
					lengthCounter++;
				}
			}
			for(int iterator = 0 ; iterator < lessArray.length; iterator++) {
				System.out.println("Элемент нового массива ["+iterator+"] = "+lessArray[iterator]);
			}
		}
		if (Math.abs(minEven)%2 == 0.0) {
			System.out.println("\nМинимальный четный элемент: "+minEven);
		} else {
			System.out.println("Чётные элементы отсутствуют");
		}
	}

}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Введите длинну массива: ");
		int N = in.nextInt();
		int[] X = new int[N];
		System.out.println("Введите элементы массива:");
		for (int i = 0; i < N; i++) {
			System.out.print("X" + i + ": ");
			X[i] = (int) in.nextDouble();
		}
		in.close();
		int minEven=0;
		for(int iterator=0;iterator<N;iterator++) {
			if(Math.abs(X[iterator])%2==0) {
				minEven=iterator;
				break;
			}
		}
		int counterOdd=0;
		for (int iterator=0;iterator<N;iterator++) {
			if(Math.abs(X[iterator])%2==1) counterOdd++;
			if((Math.abs(X[iterator])%2==0)&&(X[iterator]<=X[minEven])) minEven = iterator;
		}
		System.out.println(counterOdd);
		if(counterOdd!=0) {
			int[] lessArray = new int[counterOdd];
			int lengthCounter =0;
			for(int iterator=0;iterator<X.length;iterator++) {
				if(Math.abs(X[iterator])%2==1) {
					lessArray[lengthCounter]=X[iterator];
					lengthCounter++;
				}
			}
			for(int iterator = 0 ; iterator < lessArray.length; iterator++) {
				System.out.println("Элемент нового массива ["+iterator+"] = "+lessArray[iterator]);
			}
		}
		if (Math.abs(X[minEven])%2 == 0) {
			System.out.println("\nМинимальный четный элемент: "+"["+minEven+"]" + X[minEven]);
		} else {
			System.out.println("Чётные элементы отсутствуют");
		}
	}

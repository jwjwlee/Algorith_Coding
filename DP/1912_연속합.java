import java.util.*;

public class Main {

	public static void main(String[] args) {

		int[] arr = new int[100001];
		int[] temp = new int[100001];

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}

		temp[0] = arr[0];
		int ans = temp[0];
		for (int i = 1; i < N; i++) {
			if (temp[i - 1] + arr[i] < arr[i]) {
				temp[i] = arr[i];
			} else {
				temp[i] = temp[i - 1] + arr[i];
			}
			if(ans < temp[i]) ans = temp[i];
		}
		
		System.out.println(ans);
	}

}



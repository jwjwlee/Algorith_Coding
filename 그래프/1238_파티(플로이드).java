import java.util.*;

public class ÆÄÆ¼_1238 {

	static final int inf = 100000000;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int loc = sc.nextInt();
			
		int[][] dist = new int[N + 1][N + 1];
		
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				dist[i][j] = inf;
			}
		}
		
		for(int i = 0; i < M; i++) {
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();
			int w = sc.nextInt();
			if(dist[v1][v2] > w) {
				dist[v1][v2] = w;
			}
			
		}
		sc.close();
		
		for(int k = 1; k <= N; k++) {
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= N; j++) {
					if(i==j) continue;
					if(dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		
		int max = 0;
		for(int i = 1; i <= N; i++) {
			if(dist[loc][i] == inf || dist[i][loc] == inf) continue;
			if(max < dist[loc][i] + dist[i][loc]) {
				max = dist[loc][i] + dist[i][loc];
			}
		}
		
		System.out.println(max);		
	}
}

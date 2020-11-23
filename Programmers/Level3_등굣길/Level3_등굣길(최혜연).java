/**
 * 
 * @FileName Level3_등굣길.java
 * @author chlgpdus921
 * @date 2020. 11. 23.
 */
/* DP - 등굣길 */
public class Level3_등굣길 {

	public static void main(String[] args) {
		System.out.println(solution(4, 3, new int[][] { { 2, 2 } }));

	}

	public static int solution(int m, int n, int[][] puddles) {
		int[][] arr = new int[n + 1][m + 1];

		for (int i = 0; i < puddles.length; i++) {
			arr[puddles[i][1]][puddles[i][0]] = -1;
		}

		// n+1, m+1로 해서 모든 case 다 돌아주기
		arr[1][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == -1) {
					arr[i][j] = 0;
				} else
					arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 1000000007;
			}
		}

		return arr[n][m];
	}
}

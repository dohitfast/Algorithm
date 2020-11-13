/**
 * 
 * @FileName Level3_순위.java
 * @author chlgpdus921
 * @date 2020. 11. 13.
 */
public class Level3_순위 {

	public static void main(String[] args) {
		int[][] result = { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } };
		System.out.println(solution(5, result));
	}

	public static int solution(int n, int[][] results) {

		boolean[][] d = new boolean[n + 1][n + 1];

		for (int i = 0; i < results.length; i++) {
			int c = results[i][0];
			int r = results[i][1];
			d[c][r] = true;
		}

		// 플로이드 와샬 알고리즘
		for (int k = 1; k <= n; k++) { // 거쳐가는 노드
			for (int i = 1; i <= n; i++) { // 출발 노드
				for (int j = 1; j <= n; j++) { // 도착노드
					if (d[i][k] && d[k][j]) {
						d[i][j] = true;
					}
				}
			}
		}

		int answer = 0;
		for (int i = 1; i <= n; i++) {
			int count = 0;
			for (int j = 1; j <= n; j++) {
				if (d[i][j] || d[j][i])
					count++;
			}
			if (count == n - 1)
				answer++;

		}
		return answer;
	}
}

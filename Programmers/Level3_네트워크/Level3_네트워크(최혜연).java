import java.util.*;

/**
 * 
 * @FileName Level3_네트워크.java
 * @author chlgpdus921
 * @date 2020. 12. 5.
 */
/* 네트워크 */
public class Level3_네트워크 {
	static int cnt = 0;
	static boolean[] check;
	static Queue<Integer> q;

	public static void main(String[] args) {
		int[][] c = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
		int[][] c2 = { { 1, 1, 0 }, { 1, 1, 1 }, { 0, 1, 1 } };

		System.out.println(solution(3, c));
		System.out.println(solution(3, c2));
	}

	public static int solution(int n, int[][] computers) {
		ArrayList<Integer>[] list = new ArrayList[n + 1];

		for (int i = 0; i < list.length; i++) {
			list[i] = new ArrayList<>();
		}

		for (int i = 0; i < computers.length; i++) {
			for (int j = 0; j < computers[i].length; j++) {
				if (computers[i][j] == 1) {
					list[i + 1].add(j + 1);
					list[j + 1].add(i + 1);
				}
			}
		}

		check = new boolean[n + 1];
		q = new LinkedList<>();
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				check[i] = true;
				q.add(i);
				bfs(list);
				cnt++;
			}
		}
		return cnt;
	}

	public static void bfs(ArrayList<Integer>[] list) {

		while (!q.isEmpty()) {
			int cur = q.poll();

			for (int i = 0; i < list[cur].size(); i++) {
				int next = list[cur].get(i);
				if (!check[next]) {
					check[next] = true;
					q.add(next);
				}
			}
		}

	}
}

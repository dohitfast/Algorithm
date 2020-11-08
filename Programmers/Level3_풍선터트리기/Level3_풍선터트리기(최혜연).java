/**
 * 
 * @FileName Level3_풍선터트리기.java
 * @author chlgpdus921
 * @date 2020. 11. 8.
 */
public class Level3_풍선터트리기 {

	public static void main(String[] args) {
		int[] a = { -16, 27, 65, -2, 58, -92, -71, -68, -61, -33 };
		System.out.println(solution(a));

	}

	public static int solution(int[] a) {
		int answer = 2;

		int left = a[0];
		int right = a[a.length - 1];

		for (int i = 1; i < a.length - 1; i++) {
			if (left > a[i]) {
				left = a[i];
				answer++;
			}
			if (right > a[a.length - 1 - i]) {
				right = a[a.length - 1 - i];
				answer++;
			}
		}
		if (left == right) {
			answer -= 1;
		}
		return answer;
	}
}

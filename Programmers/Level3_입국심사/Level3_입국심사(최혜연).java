import java.util.*;

/**
 * 
 * @FileName LEVEL3_입국심사.java
 * @author chlgpdus921
 * @date 2020. 10. 31.
 */
/* 이분탐색 - 입국심사 */
public class LEVEL3_입국심사 {

	public static void main(String[] args) {
		int[] times = { 7, 10 };
		System.out.println(solution(6, times));
	}

	public static long solution(int n, int[] times) {
		long min = 1; //최소 시간
		long max = (long) times[times.length - 1] * n; //최대시간 (int*int 이기 때문에 long 변환 필요)

		while (min <= max) {
			long mid = (min + max) / 2;

			long sum = 0;
			for (int i = 0; i < times.length; i++) {
				sum += (mid / times[i]); //mid시간일 때 한명당 맡을 수 있는 사람의 수 
			}

			if (sum >= n) {
				max = mid - 1;
			} else {
				min = mid + 1; 
			}

		}

		return min;
	}

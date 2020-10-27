import java.io.*;
import java.util.*;

/**
 * 
 * @FileName BOJ1713.java
 * @author chlgpdus921
 * @date 2020. 10. 27.
 */
/* 후보 추천하기 */
public class BOJ1713 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		int size = Integer.valueOf(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		LinkedHashMap<Integer, Integer> hm = new LinkedHashMap<>();

		while (st.hasMoreElements()) {
			int key = Integer.valueOf(st.nextToken());
			if (hm.size() < n) {
				if (hm.containsKey(key)) {
					hm.replace(key, hm.get(key) + 1);
				} else
					hm.put(key, 1);
			} else if (hm.size() == n) {

				if (hm.containsKey(key)) {
					hm.replace(key, hm.get(key) + 1);
				} else {
					List<Integer> keySetList = new ArrayList<>(hm.keySet());
					Collections.sort(keySetList, (o1, o2) -> (hm.get(o1).compareTo(hm.get(o2))));

					int minKey = keySetList.get(0);
					hm.remove(minKey);
					hm.put(key, 1);
				}
			}

		}

		StringBuilder sb = new StringBuilder();
		List<Integer> keySetList = new ArrayList<>(hm.keySet());
		Collections.sort(keySetList);
		for (int key : keySetList) {
			sb.append(key + " ");
		}
		System.out.println(sb);
	}

}

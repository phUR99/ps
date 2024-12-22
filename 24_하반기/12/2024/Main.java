import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());

        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0])
                    return Integer.compare(a[0], b[0]);
                return Integer.compare(b[1], a[1]);
            }
        });

        // 입력 받기
        while (true) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (a == 0 && b == 0) {
                break;
            }
            pq.offer(new int[] { a, b }); // 시작 시간, 끝 시간을 반대로 넣음
        }

        int stTime = 0;
        int cnt = 0;

        while (stTime < m) {
            int maxEnd = stTime;

            // 큐에서 시작 시간(stTime)보다 작은 값들을 꺼내며 최대 종료 시간을 갱신
            while (!pq.isEmpty() && pq.peek()[0] <= stTime) {
                int[] current = pq.poll();
                maxEnd = Math.max(maxEnd, current[1]); // 끝 시간을 반대로 넣었으므로 -current[1]로 처리
            }

            if (maxEnd == stTime) { // 더 이상 진행할 수 없다면
                System.out.println(0);
                return;
            }

            stTime = maxEnd; // 다음 시작 시간은 이전 종료 시간
            cnt++; // 카운트 증가
        }

        System.out.println(cnt);
    }
}

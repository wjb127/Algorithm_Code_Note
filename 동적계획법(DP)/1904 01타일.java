import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args)  throws Exception {
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int tile[] = new int[1000001];
		
		tile[0] = 0;
		tile[1] = 1;
		tile[2] = 2;
		tile[3] = 3;
		
		
		
		for(int i=3;i<=n;i++) {
			
			tile[i] = (tile[i-1] + tile[i-2])%15746;
		}
		
		
		
		
		System.out.println(tile[n]);
		
		
	}
}

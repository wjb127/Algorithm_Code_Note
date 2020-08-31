
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args)  throws Exception {
		
		int arr[] = new int[1001];
	    
	    
	
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		
		int arr2[][] = new int[1001][1001];
		int ans[][] = new int[1001][1001];
		
		
		
		for(int i=0;i<N;i++) {
			
			st = new StringTokenizer(br.readLine());
			
			for(int j=0;j<M;j++) {
				
				arr2[i][j] = Integer.parseInt(st.nextToken());
			}
			
			
		}
		
		
		for(int i=0;i<N;i++) {
			
			
			
			for(int j=0;j<M;j++) {
				
				
				if(i==0 && j==0) {
					ans[i][j] = arr2[i][j];
				}
				else if(i==0) {
					ans[i][j] = ans[i][j-1] + arr2[i][j];
				}
				else if(j==0) {
					ans[i][j] = ans[i-1][j] + arr2[i][j];
				}
				else {
					
					if(ans[i-1][j] > ans[i][j-1]) {
						ans[i][j] = arr2[i][j] + ans[i-1][j];
						
					}else {
						ans[i][j] = arr2[i][j] + ans[i][j-1];
					}
					
				}
				
				
			}
			
		}
		
		
		System.out.println(ans[N-1][M-1]);
		
		
		
		br.close();
		

		
		
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int targets[3];
    char line[128];
   
    char date_str[64] = "March 13 2025"; 
    FILE *fp;

  
    printf("請輸入中獎號碼三個： ");
    scanf("%d %d %d", &targets[0], &targets[1], &targets[2]);
    printf("輸入中獎號碼為： %02d %02d %02d\n", targets[0], targets[1], targets[2]);
    printf("以下為中獎彩卷：\n");

 
    fp = fopen("lotto.txt", "r");
    if (fp == NULL) {
        printf("錯誤：無法讀取 lotto.txt (請確認是否已執行過產生程式)\n");
        return 1;
    }


    while (fgets(line, sizeof(line), fp)) {
    
        line[strcspn(line, "\n")] = 0;

      
        if (strstr(line, "====== ") && strstr(line, " 20")) {
     
            continue; 
        }

        
        char *bracket_ptr = strchr(line, '[');
        if (bracket_ptr != NULL && strstr(line, "__") == NULL) {
            int numbers[7];
            char *colon_ptr = strchr(line, ':');
            
            if (colon_ptr != NULL) {
              
                int n = sscanf(colon_ptr + 1, "%d %d %d %d %d %d %d",
                       &numbers[0], &numbers[1], &numbers[2],
                       &numbers[3], &numbers[4], &numbers[5], &numbers[6]);

                if (n == 7) {
                 
                    int match_count = 0;
                    for (int i = 0; i < 3; i++) { 
                        for (int j = 0; j < 7; j++) {
                            if (targets[i] == numbers[j]) {
                                match_count++;
                                break;
                            }
                        }
                    }

                  
                  
                    if (match_count == 3) {
                        printf("售出時間 : %s: %s\n", date_str, line);
                    }
                }
            }
        }
    }

    fclose(fp);
    return 0;
}

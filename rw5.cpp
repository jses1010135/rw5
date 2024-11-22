// rw5.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cstdio>

int main() {
    FILE* file;
    errno_t err = fopen_s(&file, "students_scores.txt", "w");
    if (err != 0) {
        std::cerr << "無法打開檔案" << std::endl;
        return 1;
    }

    // 假設已有全部同學的成績
    int student_id[50];
    float regular_scores[50];
    float midterm_scores[50];
    float final_scores[50];

    // 初始化成績（這裡僅為範例，實際應從其他來源獲取成績）
    for (int i = 0; i < 50; i++) {
        student_id[i] = i + 1;
        regular_scores[i] = 20 + rand() % 100; // 平時成績 60-100
        midterm_scores[i] = 20 + rand() % 100; // 期中考成績 60-100
        final_scores[i] = 20 + rand() % 100;   // 期末考成績 60-100
    }

    // 寫入檔案
    fprintf(file, "座號\t平時成績\t期中考成績\t期末考成績\n");
    for (int i = 0; i < 50; i++) {
        fprintf(file, "%d\t%.2f\t%.2f\t%.2f\n", student_id[i], regular_scores[i], midterm_scores[i], final_scores[i]);
    }

    fclose(file);
    std::cout << "成績已寫入 students_scores.txt 檔案中" << std::endl;

    return 0;
}



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

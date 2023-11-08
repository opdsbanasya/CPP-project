#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> input() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void addition() {
    cout<<"Enter the data of 1:\n";
    vector<vector<int>> s1 = input();
    g2:
    cout<<"Enter the data of 2:\n";
    vector<vector<int>> s2 = input();

    int n1 = s1.size();
    int m1 = s1[0].size();
    int n2 = s2.size();
    int m2 = s2[0].size();
    
    if(n1!=n2 || m1!=m2){
        cout<<"Addition is not possible! Matrices must have the same order.\n";
        goto g2;
    }


    vector<vector<int>> add(n1, vector<int>(m1));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            add[i][j] = s1[i][j] + s2[i][j];
        }
    }

    cout << "Resultant matrix after addition:\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
}

void subtraction() {
    cout<<"Enter the data of 1:\n";
    vector<vector<int>> s1 = input();
    g2:
    cout<<"Enter the data of 2:\n";
    vector<vector<int>> s2 = input();

    int n1 = s1.size();
    int m1 = s1[0].size();
    int n2 = s2.size();
    int m2 = s2[0].size();

    if(n1!=n2 || m1!=m2){
        cout<<"Substraction is not possible! Matrices must have the same order.\n";
        goto g2;
    }
    vector<vector<int>> sub(n1, vector<int>(m1));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            sub[i][j] = s1[i][j] - s2[i][j];
        }
    }
    
    cout << "Resultant matrix after addition:\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplication(){
    cout<<"Enter the data of 1:\n";
    vector<vector<int>> s1 = input();
    g2:
    cout<<"Enter the data of 2:\n";
    vector<vector<int>> s2 = input();

    int n1 = s1.size();
    int m1 = s1[0].size();
    int n2 = s2.size();
    int m2 = s2[0].size();

    if(m1 != n2){
        cout << "Impossible multiplication!\nBecause number of columns of first matrix and number of rows of second matrix must same.";
        goto g2;  
    }

    int C[n1][m2];
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m2; j++){
            int value = 0;
            for(int k = 0; k < m1; k++){
                value += s1[i][k] * s2[k][j];
            } 
            C[i][j] = value;
        }
    }
    cout << "Resultant matrix:\n";
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m2; j++){
           cout << C[i][j] << "  ";
        }
        cout << endl;
    }
  
}
void transpose(){
    vector<vector<int>> s = input();
    int n = s.size();
    int m = s[0].size();
    cout<<n<<m;

    cout<<"\nOriginal\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    int trans[m][n]; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            trans[j][i] = s[i][j]; 
        }
    }

    cout << "Transpose\n";
    for (int i=0;i<m;i++){ 
        for (int j = 0;j < n;j++) { 
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    link:
    int choice;
    cout << "Choose your choice\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n";
    cin >> choice;

    switch (choice) {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            transpose();
            break;
        default:
            cout << "Invalid choice\nPlease choose right choice:";
            goto link;
    }
    int again;
    cout<<"Do you want to again solve any problem\nEnter 1 for 'Yes' or any number for exit";
    cin>>again;
    if(again==1){
        goto link;;
    }
    return 0;
}

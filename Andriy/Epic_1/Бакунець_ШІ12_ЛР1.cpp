#include <iostream>

using namespace std;

int main() {
    cout << "Формула: (x ∨ ȳ) ⇒ ((y ∧ z̄) ⇒ (x ∨ (y ⇔ z)))" << endl << endl;

    int x;
    while (true) {
        cout << "Введіть значення x (0 або 1):" << endl;
        cin >> x;
        if (x == 0 || x == 1) break;
        cout << "Помилка! Введіть тільки 0 або 1." << endl;
    }

    int y;
    while (true) {
        cout << "Введіть значення y (0 або 1):" << endl;
        cin >> y;
        if (y == 0 || y == 1) break;
        cout << "Помилка! Введіть тільки 0 або 1." << endl;
    }

    int z;
    while (true) {
        cout << "Введіть значення z (0 або 1):" << endl;
        cin >> z;
        if (z == 0 || z == 1) break;
        cout << "Помилка! Введіть тільки 0 або 1." << endl;
    }

    cout << endl;

    bool step1 = x || !y;          // Дія 1: (x ∨ ȳ)
    bool step2 = (y == z);         // Дія 2: (y ⇔ z)
    bool step3 = x || step2;       // Дія 3: (x ∨ (y ⇔ z))
    bool step4 = y && !z;          // Дія 4: (y ∧ z̄)
    bool step5 = !step4 || step3;  // Дія 5: ((y ∧ z̄) ⇒ (x ∨ (y ⇔ z)))
    bool final_result = !step1 || step5; // Дія 6: (x ∨ ȳ) ⇒ ((y ∧ z̄) ⇒ (x ∨ (y ⇔ z)))

    cout << "Перша дія (x ∨ ȳ): " << step1 << endl;
    cout << "Друга дія (y ⇔ z): " << step2 << endl;
    cout << "Третя дія (x ∨ (y ⇔ z)): " << step3 << endl;
    cout << "Четверта дія (y ∧ z̄): " << step4 << endl;
    cout << "П'ята дія ((y ∧ z̄) ⇒ (x ∨ (y ⇔ z))): " << step5 << endl;
    cout << "Шоста дія (x ∨ ȳ) ⇒ ((y ∧ z̄) ⇒ (x ∨ (y ⇔ z))): " << final_result << endl << endl;

    cout << "Таблиця істинності:" << endl;
    cout << "x | y | z | Д1 | Д2 | Д3 | Д4 | Д5 | Д6" << endl;
    cout << "---------------------------------------" << endl;

    bool r1_1 = 0 || !0;
    bool r1_2 = (0 == 0);
    bool r1_3 = 0 || r1_2;
    bool r1_4 = 0 && !0;
    bool r1_5 = !r1_4 || r1_3;
    bool r1_6 = !r1_1 || r1_5;
    cout << "0 | 0 | 0 |  " << r1_1 << " |  " << r1_2 << " |  " << r1_3 << " |  " << r1_4 << " |  " << r1_5 << " |  " << r1_6 << endl;

    bool r2_1 = 0 || !0;
    bool r2_2 = (0 == 1);
    bool r2_3 = 0 || r2_2;
    bool r2_4 = 0 && !1;
    bool r2_5 = !r2_4 || r2_3;
    bool r2_6 = !r2_1 || r2_5;
    cout << "0 | 0 | 1 |  " << r2_1 << " |  " << r2_2 << " |  " << r2_3 << " |  " << r2_4 << " |  " << r2_5 << " |  " << r2_6 << endl;

    bool r3_1 = 0 || !1;
    bool r3_2 = (1 == 0);
    bool r3_3 = 0 || r3_2;
    bool r3_4 = 1 && !0;
    bool r3_5 = !r3_4 || r3_3;
    bool r3_6 = !r3_1 || r3_5;
    cout << "0 | 1 | 0 |  " << r3_1 << " |  " << r3_2 << " |  " << r3_3 << " |  " << r3_4 << " |  " << r3_5 << " |  " << r3_6 << endl;

    bool r4_1 = 0 || !1;
    bool r4_2 = (1 == 1);
    bool r4_3 = 0 || r4_2;
    bool r4_4 = 1 && !1;
    bool r4_5 = !r4_4 || r4_3;
    bool r4_6 = !r4_1 || r4_5;
    cout << "0 | 1 | 1 |  " << r4_1 << " |  " << r4_2 << " |  " << r4_3 << " |  " << r4_4 << " |  " << r4_5 << " |  " << r4_6 << endl;

    bool r5_1 = 1 || !0;
    bool r5_2 = (0 == 0);
    bool r5_3 = 1 || r5_2;
    bool r5_4 = 0 && !0;
    bool r5_5 = !r5_4 || r5_3;
    bool r5_6 = !r5_1 || r5_5;
    cout << "1 | 0 | 0 |  " << r5_1 << " |  " << r5_2 << " |  " << r5_3 << " |  " << r5_4 << " |  " << r5_5 << " |  " << r5_6 << endl;

    bool r6_1 = 1 || !0;
    bool r6_2 = (0 == 1);
    bool r6_3 = 1 || r6_2;
    bool r6_4 = 0 && !1;
    bool r6_5 = !r6_4 || r6_3;
    bool r6_6 = !r6_1 || r6_5;
    cout << "1 | 0 | 1 |  " << r6_1 << " |  " << r6_2 << " |  " << r6_3 << " |  " << r6_4 << " |  " << r6_5 << " |  " << r6_6 << endl;

    bool r7_1 = 1 || !1;
    bool r7_2 = (1 == 0);
    bool r7_3 = 1 || r7_2;
    bool r7_4 = 1 && !0;
    bool r7_5 = !r7_4 || r7_3;
    bool r7_6 = !r7_1 || r7_5;
    cout << "1 | 1 | 0 |  " << r7_1 << " |  " << r7_2 << " |  " << r7_3 << " |  " << r7_4 << " |  " << r7_5 << " |  " << r7_6 << endl;

    bool r8_1 = 1 || !1;
    bool r8_2 = (1 == 1);
    bool r8_3 = 1 || r8_2;
    bool r8_4 = 1 && !1;
    bool r8_5 = !r8_4 || r8_3;
    bool r8_6 = !r8_1 || r8_5;
    cout << "1 | 1 | 1 |  " << r8_1 << " |  " << r8_2 << " |  " << r8_3 << " |  " << r8_4 << " |  " << r8_5 << " |  " << r8_6 << endl;

    cout << endl << "Висновок: Формула є тотожністю." << endl;

    return 0;
}
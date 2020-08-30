#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    int s, c;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "Capacity: " << vi.capacity() << " " << "Size: " << vi.size() << endl;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "Capacity: " << vi.capacity() << " " << "Size: " << vi.size() << endl;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "Capacity: " << vi.capacity() << " " << "Size: " << vi.size() << endl;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "Capacity: " << vi.capacity() << " " << "Size: " << vi.size() << endl;

    for (s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "Capacity: " << vi.capacity() << " " << "Size: " << vi.size() << endl;

    return 0;        
}

/*Output:
Capacity: 1 Size: 1
Capacity: 2 Size: 2
Capacity: 4 Size: 3
Capacity: 8 Size: 5
Capacity: 16 Size: 9
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;



class DongVatPrototype
{
public:
    virtual DongVatPrototype *clone() const = 0;
    virtual void tiengKeu() const = 0;
    virtual void xuatThongTin() const = 0;
    virtual void nhapThongTin() = 0;
    virtual void suaThongTin() = 0;
};

class Meo : public DongVatPrototype
{
private:
    string ten;
    int tuoi;
    double canNang;
    bool gioiTinh;

public:
    Meo(string ten, int tuoi, double canNang, bool gioiTinh)
        : ten(ten), tuoi(tuoi), canNang(canNang), gioiTinh(gioiTinh) {}

    DongVatPrototype *clone() const override
    {
        return new Meo(*this);
    }

    void tiengKeu() const override
    {
        cout << "Meo meo!" << endl;
    }

    void xuatThongTin() const override
    {
        cout << "Ten: " << ten << ", Tuoi: " << tuoi << " tuoi, Can nang: " << canNang << " kg, Gioi tinh: " << (gioiTinh ? "Duc" : "Cai") << endl;
    }

    void nhapThongTin() override
    {
        cout << "Nhap ten: ";
        getline(cin, ten);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap can nang: ";
        cin >> canNang;

        int gioiTinhOption;
        cout << "Chon gioi tinh (1 - Duc, 0 - Cai): ";
        cin >> gioiTinhOption;
        gioiTinh = gioiTinhOption == 1 ? true : false;

        cin.ignore(); // Đọc bỏ dấu enter sau khi nhập gioiTinh
    }

    void suaThongTin() override
    {
        cout << "Nhap thong tin sua doi (nhap 0 neu muon giu thong tin ban dau):" << endl;

        string tenMoi;
        int tuoiMoi;
        double canNangMoi;
        int gioiTinhOption;

        cout << "Nhap ten: ";
        getline(cin, tenMoi);
        if (tenMoi == "0")
        {
            tenMoi = ten;
        }

        cout << "Nhap tuoi: ";
        cin >> tuoiMoi;
        if (tuoiMoi == 0)
        {
            tuoiMoi = tuoi;
        }

        cout << "Nhap can nang: ";
        cin >> canNangMoi;
        if (canNangMoi == 0)
        {
            canNangMoi = canNang;
        }

        // Cập nhật thông tin mới
        ten = tenMoi;
        tuoi = tuoiMoi;
        canNang = canNangMoi;
    }
};

class Cho : public DongVatPrototype
{
private:
    string ten;
    int tuoi;
    double canNang;
    bool gioiTinh;

public:
    Cho(string ten, int tuoi, double canNang, bool gioiTinh)
        : ten(ten), tuoi(tuoi), canNang(canNang), gioiTinh(gioiTinh) {}

    DongVatPrototype *clone() const override
    {
        return new Cho(*this);
    }

    void tiengKeu() const override
    {
        cout << "Gau gau!" << endl;
    }

    void xuatThongTin() const override
    {
        cout << "Ten: " << ten << ", Tuoi: " << tuoi << " tuoi, Can nang: " << canNang << " kg, Gioi tinh: " << (gioiTinh ? "Duc" : "Cai") << endl;
    }

    void nhapThongTin() override
    {
        cout << "Nhap ten: ";
        getline(cin, ten);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap can nang: ";
        cin >> canNang;

        int gioiTinhOption;
        cout << "Chon gioi tinh (1 - Duc, 0 - Cai): ";
        cin >> gioiTinhOption;
        gioiTinh = gioiTinhOption == 1 ? true : false;

        cin.ignore(); // Đọc bỏ dấu enter sau khi nhập gioiTinh
    }

    void suaThongTin() override
    {
        cout << "Nhap thong tin sua doi (nhap 0 neu muon giu thong tin ban dau):" << endl;

        string tenMoi;
        int tuoiMoi;
        double canNangMoi;
        int gioiTinhOption;

        cout << "Nhap ten: ";
        getline(cin, tenMoi);
        if (tenMoi == "0")
        {
            tenMoi = ten;
        }

        cout << "Nhap tuoi: ";
        cin >> tuoiMoi;
        if (tuoiMoi == 0)
        {
            tuoiMoi = tuoi;
        }

        cout << "Nhap can nang: ";
        cin >> canNangMoi;
        if (canNangMoi == 0)
        {
            canNangMoi = canNang;
        }
        cin.ignore(); // Đọc bỏ dấu enter sau khi nhập gioiTinh

        // Cập nhật thông tin mới
        ten = tenMoi;
        tuoi = tuoiMoi;
        canNang = canNangMoi;
    }
};

class QuanLyDongVatPrototype
{
private:
    unordered_map<string, DongVatPrototype *> prototypes;

public:
    QuanLyDongVatPrototype()
    {
        prototypes["meo"] = new Meo("Tom", 2, 3.5, true);
        prototypes["cho"] = new Cho("Spike", 3, 10.2, true);
    }

    DongVatPrototype *layDongVat(string loai)
    {
        return prototypes[loai]->clone();
    }
};

int main()
{
    QuanLyDongVatPrototype quanLy;

    DongVatPrototype *conMeo = quanLy.layDongVat("meo");
    DongVatPrototype *conCho = quanLy.layDongVat("cho");

    cout << "Nhap thong tin con meo: " << endl;
    conMeo->nhapThongTin();

    cout << "\nThong tin con meo sau khi nhap: " << endl;
    conMeo->xuatThongTin();

    cout << "\nNhap thong tin con cho: " << endl;
    conCho->nhapThongTin();

    cout << "\nThong tin con cho sau khi nhap: " << endl;
    conCho->xuatThongTin();

    cout << endl;

    while (true)
    {
        cout << "\nBan muon sua thong tin cua meo hay cho? (Nhap 'meo' hoac 'cho', nhap 'exit' de thoat): ";
        string luaChon;
        getline(cin, luaChon);

        if (luaChon == "exit")
        {
            break;
        }
        else if (luaChon == "meo")
        {
            cout << "Ban muon sua thong tin cua meo?(Chon 1 de 'sua', chon 0 de 'thoat'): ";
            int luaChonMeo;
            cin >> luaChonMeo;
            cin.ignore(); // Đọc bỏ dấu enter sau khi nhập luaChonMeo

            switch (luaChonMeo)
            {
            case 1:
                conMeo->suaThongTin();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
            }

            cout << "\nThong tin con meo sau khi sua: " << endl;
            conMeo->xuatThongTin();
        }
        else if (luaChon == "cho")
        {
            cout << "Ban muon sua thong tin cua cho?(Chon 1 de 'sua', chon 0 de 'thoat'): ";
            int luaChonCho;
            cin >> luaChonCho;
            cin.ignore(); // Đọc bỏ dấu enter sau khi nhập luaChonCho

            switch (luaChonCho)
            {
            case 1:
                conCho->suaThongTin();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
            }

            cout << "\nThong tin con cho sau khi sua: " << endl;
            conCho->xuatThongTin();
        }
        else
        {
            cout << "Lua chon khong hop le!" << endl;
        }
    }

    // giải phóng bộ nhớ cấp phát
    delete conMeo;
    delete conCho;

    return 0;
}

package tren_lop;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class_oop QuanLyNhanSu {
    private static ArrayList<NhanVien> danhSachNV = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            System.out.println("+---Menu---");
            System.out.println("1. Nhập danh sách nhân viên");
            System.out.println("2. Xuất danh sách nhân viên");
            System.out.println("0. Thoát");
            System.out.print("Chọn chương trình: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1 -> nhapDanhSachNV();
                case 2 -> xuatDanhSachNV();

                case 0 -> {
                    System.out.println("Thoát chương trình.");
                    return;
                }
                default -> System.out.println("Lựa chọn không hợp lệ.");
            }
        }
    }

    private static void nhapDanhSachNV() {
        System.out.print("Nhập số lượng nhân viên: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.print("Nhập loại nhân viên (1: Hành chính, 2: Tiếp thị, 3: Trưởng phòng): ");
            int loai = scanner.nextInt();
            scanner.nextLine();

            System.out.print("Nhập mã NV: ");
            String maNV = scanner.nextLine();
            System.out.print("Nhập họ tên: ");
            String hoTen = scanner.nextLine();
            System.out.print("Nhập lương: ");
            double luong = scanner.nextDouble();
            scanner.nextLine(); // Consume newline

            switch (loai) {
                case 1 -> danhSachNV.add(new NhanVienHanhChinh(maNV, hoTen, luong));
                case 2 -> {
                    System.out.print("Nhập doanh số: ");
                    double doanhSo = scanner.nextDouble();
                    System.out.print("Nhập tỉ lệ hoa hồng: ");
                    double hueHong = scanner.nextDouble();
                    scanner.nextLine();
                    danhSachNV.add(new NhanVienTiepThi(maNV, hoTen, luong, doanhSo, hueHong));
                }
                case 3 -> {
                    System.out.print("Nhập lương trách nhiệm: ");
                    double luongTrachNhiem = scanner.nextDouble();
                    scanner.nextLine();
                    danhSachNV.add(new TruongPhong(maNV, hoTen, luong, luongTrachNhiem));
                }
                default -> {
                    System.out.println("Loại nhân viên không hợp lệ.");
                    i--;
                }
            }
        }
    }

    private static void xuatDanhSachNV() {
        for (NhanVien nv : danhSachNV) {
            System.out.println(nv);
        }
    }

    private static void timKiemNVTheoMa() {
        System.out.print("Nhập mã NV cần tìm: ");
        String maNV = scanner.nextLine();
        for (NhanVien nv : danhSachNV) {
            if (nv.getMaNV().equals(maNV)) {
                System.out.println(nv);
                return;
            }
        }
        System.out.println("Không tìm thấy nhân viên có mã " + maNV);
    }

    private static void xoaNVTheoMa() {
        System.out.print("Nhập mã NV cần xóa: ");
        String maNV = scanner.nextLine();
        danhSachNV.removeIf(nv -> nv.getMaNV().equals(maNV));
        System.out.println("Đã xóa nhân viên có mã " + maNV);
    }

    private static void capNhatNVTheoMa() {
    }

    private static void timNVTheoKhoangLuong() {
        System.out.print("Nhập lương tối thiểu: ");
        double min = scanner.nextDouble();
        System.out.print("Nhập lương tối đa: ");
        double max = scanner.nextDouble();
        scanner.nextLine(); // Consume newline

        for (NhanVien nv : danhSachNV) {
            if (nv.getLuong() >= min && nv.getLuong() <= max) {
                System.out.println(nv);
            }
        }
    }

    private static void sapXepNVTheoHoTen() {
        Collections.sort(danhSachNV, Comparator.comparing(NhanVien::getHoTen));
        System.out.println("Đã sắp xếp nhân viên theo họ tên.");
    }

    private static void sapXepNVTheoThuNhap() {
        Collections.sort(danhSachNV, Comparator.comparing(NhanVien::tinhThuNhap));
        System.out.println("Đã sắp xếp nhân viên theo thu nhập.");
    }

    private static void xuatTop5NVThuNhapCaoNhat() {
        danhSachNV.sort(Comparator.comparing(NhanVien::tinhThuNhap).reversed());
        int count = Math.min(5, danhSachNV.size());
        for (int i = 0; i < count; i++) {
            System.out.println(danhSachNV.get(i));
        }
    }
}
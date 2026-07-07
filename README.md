#  Graph Adjacency Matrix - C++

Đồ án môn **Cấu trúc dữ liệu & Giải thuật** xây dựng chương trình quản lý và xử lý đồ thị bằng **Ma trận kề (Adjacency Matrix)** bằng ngôn ngữ **C++**.

Project hỗ trợ cả:

- Đồ thị vô hướng có trọng số (Weighted Undirected Graph)
- Đồ thị có hướng có trọng số (Weighted Directed Graph)

---

## Features

### Đọc dữ liệu

- Đọc ma trận kề từ file `.txt`
- Hiển thị ma trận kề

---

### Xử lý đỉnh

- Tính bậc ra của đỉnh
- Tính bậc vào của đỉnh
- Tính bậc của đỉnh (đồ thị vô hướng)
- Xuất các đỉnh kề
- Kiểm tra đỉnh cô lập
- Đếm số đỉnh cô lập
- Tìm đỉnh có bậc ra lớn nhất
- Tìm đỉnh có bậc ra nhỏ nhất
- Tìm đỉnh kề có bậc ra lớn nhất
- Tìm đỉnh kề có bậc ra nhỏ nhất
- Tìm đỉnh kề có trọng số lớn nhất
- Tìm đỉnh kề có trọng số nhỏ nhất

---

### Xử lý cạnh

- Trả về tập cạnh của đồ thị
- Đếm số cạnh
- Tìm cạnh có trọng số lớn nhất
- Tìm cạnh có trọng số nhỏ nhất
- Tìm cạnh đi vào có trọng số lớn nhất
- Tìm cạnh đi vào có trọng số nhỏ nhất
- Tìm cạnh đi ra có trọng số lớn nhất
- Tìm cạnh đi ra có trọng số nhỏ nhất
- Tính tổng trọng số các cạnh
- Tính tổng trọng số các cạnh đi vào
- Tính tổng trọng số các cạnh đi ra

---

### Chuyển đổi biểu diễn đồ thị

- Tập cạnh ➜ Ma trận kề
- Ma trận kề ➜ Danh sách kề

---

### Thao tác trên đồ thị

- Đảo hướng một cạnh
- Đảo hướng toàn bộ đồ thị
- Tạo ma trận đảo

---

## Cấu trúc project

```
Graph-Adjacency-Matrix/
│
├── Header.h          # Khai báo cấu trúc dữ liệu và prototype
├── Source.cpp        # Cài đặt các thuật toán
├── Source1.cpp       # Chương trình menu chính
├── dothi1.txt        # File dữ liệu đồ thị vô hướng
├── dothi2.txt        # File dữ liệu đồ thị có hướng
└── README.md
```

---

## 🛠️ Công nghệ sử dụng

- C++
- Visual Studio
- File Input/Output
- Struct
- Pointer
- Linked List
- Adjacency Matrix
- Adjacency List

---

## Các cấu trúc dữ liệu

### Vertex

```cpp
typedef int VERTEX;
```

### Edge

```cpp
struct EDGE {
    VERTEX org;
    VERTEX des;
    int wei;
};
```

### Adjacency Matrix

```cpp
struct AjencyMatrix {
    int ds[MAXV][MAXV];
    int n;
};
```

### Adjacency List

```cpp
struct NODE {
    int dinhke;
    int trongso;
    NODE* link;
};
```

---

## Chạy chương trình

1. Clone project

```bash
git clone https://github.com/yourusername/Graph-Adjacency-Matrix.git
```

2. Mở bằng **Visual Studio**

3. Build Project

4. Chạy chương trình

---

## Menu chức năng

Chương trình gồm **44 chức năng**, bao gồm:

| STT | Chức năng |
|----|-----------------------------|
|1|Đọc đồ thị vô hướng|
|2|Đọc đồ thị có hướng|
|3|Tính bậc ra|
|4|Tính bậc đỉnh|
|5|Lấy tập cạnh|
|6|Tạo ma trận từ tập cạnh (DTVH)|
|7|Tạo ma trận từ tập cạnh (DTCH)|
|8|Đỉnh kề có trọng số lớn nhất|
|9|Ma trận đảo|
|10|Bậc vào|
|11|Xuất đỉnh kề|
|12|Tổng bậc ra|
|13|Tổng bậc vào|
|14|Tổng bậc đồ thị vô hướng|
|15|Kiểm tra đỉnh cô lập|
|16|Đếm đỉnh cô lập|
|17|Đếm cạnh DTCH|
|18|Đếm cạnh DTVH|
|19|Cạnh lớn nhất|
|20|Cạnh nhỏ nhất|
|21|Cạnh lớn nhất DTVH|
|22|Cạnh nhỏ nhất DTVH|
|23|Tổng trọng số DTCH|
|24|Tổng trọng số DTVH|
|25|Cạnh vào lớn nhất|
|26|Cạnh vào nhỏ nhất|
|27|Cạnh ra lớn nhất|
|28|Cạnh ra nhỏ nhất|
|29|Đảo hướng một cạnh|
|30|Đảo hướng toàn bộ|
|31|Trả về tập cạnh|
|32|Chuyển sang danh sách kề|
|33|Đỉnh có bậc ra lớn nhất|
|34|Đỉnh có bậc ra nhỏ nhất|
|35|Đỉnh kề có bậc ra lớn nhất|
|36|Đỉnh kề có bậc ra nhỏ nhất|
|37|Tìm cạnh lớn nhất|
|38|Tìm cạnh nhỏ nhất|
|39|Tổng trọng số cạnh ra|
|40|Tổng trọng số cạnh vào|
|41|Cạnh kề lớn nhất|
|42|Cạnh kề nhỏ nhất|
|43|Đỉnh kề có trọng số lớn nhất|
|44|Đỉnh kề có trọng số nhỏ nhất|

---

## Kiến thức áp dụng

- Đồ thị (Graph)
- Ma trận kề (Adjacency Matrix)
- Danh sách kề (Adjacency List)
- Đồ thị có hướng
- Đồ thị vô hướng
- Đồ thị có trọng số
- Struct trong C++
- Con trỏ (Pointer)
- Linked List
- File Processing
- Thuật toán xử lý đồ thị

---

## Tác giả

**Dương Tấn Lộc**


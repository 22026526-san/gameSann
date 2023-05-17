# Giới thiệu:
- võ QUANG SÁNG - 22026526 - K67J 
# Ý Tưởng : 
- FlappyBird viết bằng c++ và SDL2
# Lí Do : 
- đây là game khá phổ biến và đã được viết bởi nhiều ngôn ngữ như python, c# , c++ kết hợp js , v...v.. nên em sẽ có 
được nhiều nguồn tài liệu để tham khảo.
# Giới thiệu : 
1, Tính Năng 
- Game có thể đổi icon nhân vật ở PauseTab.
   + red_bird(ứng với background ban ngày).
   +  black_bird(ứng với background ban đêm).
- có thể tắt hoặc bật nhạc trong PauseTab.
- có chức năng BestScore lưu điểm cao nhất của người chơi.
2, Cách Chơi
- Sử dụng các phím SPACE,UP,CLICK CHUỘT để điều khiển chim đi qua các khoảng không giữa 2 cột ,mỗi lần như thế sẽ được +1 điểm.
- Người chơi có thể bấm phím ESC để di chuyển đến PauseTab trong lúc chơi để tùy chỉnh icon nhân vật hoặc bật tắt âm thanh. 

# Hướng Dẫn Cài Đặt:
- tải và cài đặt vs code.
- tải mingw64 và cài môi trường c++ cho máy. 
- tải các thư viện hỗ trợ như : SDL2_image , SDL2_ttf , SDL2_mixer , SDL2.
- tải project về dưới dạng file zip 
- mở project bằng vs code , vào mục makefile thay đổi link include (IC) và link lib (LC) theo máy của bạn , sau đó mở terminal ở vs code gõ 'mingw32-make' để tạo file exe và gõ file exe ra bấm enter để chạy.
# Hướng cải thiện tiếp theo: 
- tạo ra AI có thể chơi FlappyBird.
- tạo ra các đồng xu ở giữa hai cột từ đó bot AI và người chơi có thể cùng lúc chơi và tính điểm theo số đồng xu ăn được.
# Tài Liệu Tham Khảo:
- LazyFoo(cách render ảnh , load âm thanh , ...).
- YouTube(các video code game FlappyBird).
- Google(tham khảo code , một số thuật toán ở trong game , ...).


                            
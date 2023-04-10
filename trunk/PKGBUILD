# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: ThatOneCalculator <kainoa@t1c.dev>

pkgname=hyprland
pkgver=0.24.1
pkgrel=1
pkgdesc='a highly customizable dynamic tiling Wayland compositor'
arch=(x86_64 aarch64)
url="https://github.com/hyprwm/${pkgname^}"
license=(BSD)
depends=(cairo
         gcc-libs
         glibc
         glslang
         libdisplay-info
         libdrm
         libglvnd
         libinput
         libliftoff
         libx11
         libxcb
         libxcomposite
         libxfixes
         libxkbcommon
         libxrender
         opengl-driver
         pango
         pixman
         pixman
         polkit
         seatd
         systemd-libs
         vulkan-icd-loader
         vulkan-validation-layers
         wayland
         wayland-protocols
         xcb-proto
         xcb-util
         xcb-util-errors
         xcb-util-keysyms
         xcb-util-renderutil
         xcb-util-wm
         xorg-xinput
         xorg-xwayland)
depends+=(libdisplay-info.so)
makedepends=(cmake
             gdb
             meson
             ninja
             vulkan-headers
             xorgproto)
_archive="${pkgname^}-$pkgver"
source=("$_archive.tar.gz::$url/releases/download/v$pkgver/source-v$pkgver.tar.gz")
sha256sums=('91725f5b2382ffa53bed02d61efde5216290073fb2aff6bb414da3c0cd66ef36')

prepare() {
	ln -sf hyprland-source "$_archive"
	cd "$_archive"
	make fixwlr
	sed -i -e '/^release:/{n;s/-D/-DCMAKE_SKIP_RPATH=ON -D/}' Makefile
}

build() {
	cd "$_archive"
	pushd subprojects/wlroots
	meson build/ --prefix="$srcdir/tmpwlr" --buildtype=release
	ninja -C build/
	mkdir -p "$srcdir/tmpwlr"
	ninja -C build/ install
	popd
	pushd subprojects/udis86
	cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Release -H./ -B./build -G Ninja
	cmake --build ./build --config Release --target all
	popd
	make protocols
	make release
	pushd hyprctl
	make all
}

package() {
	cd "$_archive"
	install -Dm0755 -t "$pkgdir/usr/bin" build/Hyprland
	install -Dm0755 -t "$pkgdir/usr/bin" hyprctl/hyprctl
	install -Dm0644 -t "$pkgdir/usr/share/$pkgname" assets/*.png
	install -Dm0644 -t "$pkgdir/usr/share/wayland-sessions" "example/$pkgname.desktop"
	install -Dm0644 -t "$pkgdir/usr/share/$pkgname" "example/$pkgname.conf"
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
	install -Dm0755 -t "$pkgdir/usr/lib" "$srcdir/tmpwlr/lib/libwlroots.so.12032"
}

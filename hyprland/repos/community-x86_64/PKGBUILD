# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: ThatOneCalculator <kainoa@t1c.dev>

pkgname=hyprland
pkgver=0.25.0
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
sha256sums=('c91029085daa80437b1ef5ac10cd849795a8ce32d36663eff949af5f9337217b')

prepare() {
	ln -sf hyprland-source "$_archive"
	cd "$_archive"
	make fixwlr
	sed -i -e '/^release:/{n;s/-D/-DCMAKE_SKIP_RPATH=ON -D/}' Makefile
	# https://github.com/hyprwm/Hyprland/issues/2226
	sed -i -e 's/\(.*GIT_COMMIT_HASH \)\(.*\)/\1"\2"/' src/defines.hpp
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

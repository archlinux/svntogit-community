# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: ThatOneCalculator <kainoa@t1c.dev>

pkgname=hyprland
pkgver=0.23.0beta
pkgrel=3
pkgdesc='a highly customizable dynamic tiling Wayland compositor'
arch=(x86_64 aarch64)
url="https://github.com/hyprwm/${pkgname^}"
license=(BSD)
depends=(cairo
         glslang
         libdisplay-info
         libinput
         libliftoff
         libx11
         libxcb
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
makedepends=(cmake
             gdb
             meson
             ninja
             vulkan-headers
             wayland-protocols
             xorgproto)
_archive="${pkgname^}-$pkgver"
source=("$_archive.tar.gz::$url/releases/download/v$pkgver/source-v$pkgver.tar.gz")
sha256sums=('779c35b0256cffe681586e4c34d63cf46fe4f263eff5370d06ae77a96e5de01f')

prepare() {
	ln -s hyprland-source "$_archive"
	cd "$_archive"
	make fixwlr
}

build() {
	set -x
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
	install -Dm0755 -t "$pkgdir/usr/bin" hyprland-source/build/{Hyprland,hyprctl}
	install -Dm0644 -t "$pkgdir/usr/share/hyprland" hyprland-source/assets/*.png
	install -Dm0644 -t "$pkgdir/usr/share/wayland-sessions" hyprland-source/example/hyprland.desktop
	install -Dm0644 -t "$pkgdir/usr/share/hyprland" hyprland-source/example/hyprland.conf
	install -Dm0755 -t "$pkgdir/usr/lib" "$srcdir/tmpwlr/lib/libwlroots.so.12032"
}

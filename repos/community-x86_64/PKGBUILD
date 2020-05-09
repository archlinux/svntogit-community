# Maintainer: Daurnimator <daurnimator@archlinux.org>
# Contributor: Alexander F Rødseth <xyproto@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Lucas Hermann Negri <kkndrox@gmail.com>

pkgbase=lua-bitop
pkgname=(lua51-bitop lua52-bitop)
pkgver=1.0.2
pkgrel=9
pkgdesc='Bitwise operations on numbers'
arch=('x86_64')
license=('MIT')
url='https://bitop.luajit.org/'
makedepends=('lua51' 'lua52')
source=("https://bitop.luajit.org/download/LuaBitOp-$pkgver.tar.gz"
        "LICENSE")
sha256sums=('1207c9293dcd52eb9dca6538d1b87352bd510f4e760938f5048433f7f272ce99'
            'dac73bcdefc05b065d36487f43a629684615051973d10f21e0fa4305e8557e5a')

prepare() {
  cp -a "LuaBitOp-$pkgver" "LuaBitOp51-$pkgver"
  cp -a "LuaBitOp-$pkgver" "LuaBitOp52-$pkgver"
}

build() {
  make -C "LuaBitOp51-$pkgver" INCLUDES=' -I/usr/include/lua5.1' LUA='lua5.1'
  make -C "LuaBitOp52-$pkgver" INCLUDES=' -I/usr/include/lua5.2' LUA='lua5.2'
}

check() {
  make -C "LuaBitOp51-$pkgver" LUA='lua5.1' test
  make -C "LuaBitOp52-$pkgver" LUA='lua5.2' test
}

package_lua51-bitop() {
  install -Dm 644 "LuaBitOp51-$pkgver/bit.so" "$pkgdir/usr/lib/lua/5.1/bit.so"
  install -Dm 644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_lua52-bitop() {
  install -Dm 644 "LuaBitOp52-$pkgver/bit.so" "$pkgdir/usr/lib/lua/5.2/bit.so"
  install -Dm 644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

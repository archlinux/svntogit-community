# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.14.15
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 git)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(!lto)
source=($url/archive/v$pkgver/$pkgname-v$pkgver.tar.gz)
sha512sums=('1ab6a20d1681df32e7e540500e8632887c27f89cf405ef62f188f8509ddab6f88ef32d3018bd56ed3c420e8736db264b01df75942503cbbbe3d613e94e9d3fc8')
b2sums=('2463c0da03556a78e18b8f37c77ba7ed82bb7bcbe5976cb73c27bea741f348defd1cd1ea6944c1f2994853819dc9bb83d29883076aa2e9ac2a66b62fba4ee304')

prepare() {
  cd $pkgname-$pkgver
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd $pkgname-$pkgver
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so)

  cd $pkgname-$pkgver
  install -vDm 755 target/release/maturin -t "$pkgdir/usr/bin/"
  install -vDm 644 {Changelog,README}.md -t "$pkgdir/usr/share/doc/$pkgname/"
}

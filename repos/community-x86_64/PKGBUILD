# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.13
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(!lto)
source=($pkgname-$pkgver.tar.gz::https://github.com/PyO3/$pkgname/archive/refs/tags/v$pkgver.tar.gz)
sha512sums=('d8253082de89204db623e27a3f1c6215c57366fa9a0e19f5a3aef4613311539e2ec678724c23d00db0f441bfaba65bb684002c6090374bee7565903532857ede')
b2sums=('a1812231045a8463aa2afa3be0dc88821a24916c50b5b62038f20d292bdd1da0242d175514fccb566f26dea52db77930a594aa9b87c4085aae0e0f6d04433f5a')

prepare() {
  cd $pkgname-$pkgver
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd $pkgname-$pkgver
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so libdbus-1.so)

  cd $pkgname-$pkgver
  install -vDm 755 target/release/maturin -t "$pkgdir/usr/bin/"
  install -vDm 644 {Changelog,Readme}.md -t "$pkgdir/usr/share/doc/$pkgname/"
}

# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.11.4
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
source=(git+https://github.com/PyO3/maturin#tag=v$pkgver)
sha256sums=('SKIP')
validpgpkeys=('07515D832489235391FD5799305BDEA95BCA5CBF')  # konstin <konstin@mailbox.org>

prepare() {
  cd maturin
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd maturin
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so libdbus-1.so)

  cd maturin
  install -vDm 755 target/release/maturin -t "${pkgdir}/usr/bin"
  install -vDm 644 {Changelog,Readme}.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

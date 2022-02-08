# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.7
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(!lto)
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/PyO3/${pkgname}/archive/refs/tags/v${pkgver}.tar.gz)
sha512sums=('00dd33b89bf02655ac0645bfddb4f4c1127c79cc9f7d8092084037b2aecf37988f99212e6510ce6ae9248e009c8f076eb1504611065f342f3bc1166a3f45a349')
b2sums=('91f614813e322ce95ed65e06cf9b15c948650f33fae3389e88d64f2cda978d3013ce681beb194d2860032844eec1550d0233e35e7853e004d1a98b8fc3774346')

prepare() {
  cd ${pkgname}-${pkgver}
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd ${pkgname}-${pkgver}
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so libdbus-1.so)

  cd ${pkgname}-${pkgver}
  install -vDm 755 target/release/maturin -t "${pkgdir}/usr/bin"
  install -vDm 644 {Changelog,Readme}.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

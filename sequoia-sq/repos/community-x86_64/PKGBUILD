# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=sequoia-sq
pkgver=0.29.0
_commit=bc9bc72fd670eda6bba973352b8053d67b1a180a  # refs/tags/v0.29.0
pkgrel=3
pkgdesc='Command-line frontends for Sequoia'
url='https://sequoia-pgp.org/'
arch=('x86_64')
license=('GPL2')
groups=('sequoia')
replaces=('sequoia')
depends=(
  'bzip2' 'libbz2.so'
  'gcc-libs'
  'glibc'
  'gmp'
  'nettle' 'libnettle.so' 'libhogweed.so'
  'openssl'
)
makedepends=(
  'git'
  'cargo'
  'clang'
)
options=('!lto')
source=("git+https://gitlab.com/sequoia-pgp/sequoia-sq.git#tag=$_commit?signed")
sha512sums=('SKIP')
validpgpkeys=(
  D2F2C5D45BE9FDE6A4EE0AAF31855247603831FD # justus@sequoia-pgp.org
  CBCD8F030588653EEDD7E2659B7DD433F254904A # justus@sequoia-pgp.org
  8F17777118A33DDA9BA48E62AACB3243630052D9  # Neal H. Walfield <neal@sequoia-pgp.org>
)

prepare() {
  cd $pkgname
  export RUSTUP_TOOLCHAIN=stable
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd $pkgname
  export CARGO_TARGET_DIR=../target
  export RUSTUP_TOOLCHAIN=stable
  # NOTE: we select specific (default) features, as there are multiple crypto backends
  cargo build --release --frozen --features 'default'

}

check() {
  cd $pkgname
  export RUSTUP_TOOLCHAIN=stable
  cargo test --release --frozen --features 'default'
}

package() {
  install -Dm 755 target/release/sq -t "${pkgdir}/usr/bin"

  install -Dm 644 target/sq.bash "${pkgdir}/usr/share/bash-completion/completions/sq"
  install -Dm 644 target/_sq -t "${pkgdir}/usr/share/zsh/site-functions"
  install -Dm 644 target/sq.fish -t "${pkgdir}/usr/share/fish/vendor_completions.d"

  install -Dm 644 $pkgname/man-sq/*.1 -t "${pkgdir}/usr/share/man/man1"
}

# vim: ts=2 sw=2 et:

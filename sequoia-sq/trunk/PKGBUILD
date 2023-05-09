# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=sequoia-sq
pkgver=0.30.0
_commit=2f3f75e8c2117ae2ff118219dc7a118eb8f52b0b  # refs/tags/v0.30.0
pkgrel=2
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
  'sqlite'
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
  # NOTE: we use a different target dir, as otherwise cargo test --release alters the sq binary
  # https://gitlab.com/sequoia-pgp/sequoia-sq/-/issues/96
  export CARGO_TARGET_DIR=../target-test
  export RUSTUP_TOOLCHAIN=stable
  cargo test --release --frozen --features 'default'
}

package() {
  install -Dm 755 target/release/sq -t "${pkgdir}/usr/bin"

  install -Dm 644 target/sq.bash "${pkgdir}/usr/share/bash-completion/completions/sq"
  install -Dm 644 target/_sq -t "${pkgdir}/usr/share/zsh/site-functions"
  install -Dm 644 target/sq.fish -t "${pkgdir}/usr/share/fish/vendor_completions.d"

  for manpage in target/release/build/$pkgname-*/out/*.1; do
    install -Dm 644 $manpage -t "${pkgdir}/usr/share/man/man1/"
  done
}

# vim: ts=2 sw=2 et:

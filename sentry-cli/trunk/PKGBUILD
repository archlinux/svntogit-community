# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Contributor: Bambang Catur Pamungkas <bambangcaturz@gmail.com>

pkgname=sentry-cli
pkgver=1.71.0
pkgrel=1
pkgdesc="A command line utility to work with Sentry"
arch=('x86_64')
url="https://docs.sentry.io/cli/"
license=('BSD')
depends=('gcc-libs' 'zlib')
makedepends=('cargo')
source=("$pkgname-$pkgver.tar.gz"::https://github.com/getsentry/sentry-cli/archive/${pkgver}.tar.gz)
sha256sums=('6a23dde41298a7aedd6885460e31fa2f4bcf29ab0cb5b0db2f527b234cce0020')

build() {
  cd $pkgname-$pkgver
  cargo build --release --locked
}

check() {
  cd $pkgname-$pkgver
  cargo test --release --locked -- --skip vcs
}

package() {
  cd $pkgname-$pkgver
  install -Dm755 target/release/sentry-cli "$pkgdir"/usr/bin/sentry-cli
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:

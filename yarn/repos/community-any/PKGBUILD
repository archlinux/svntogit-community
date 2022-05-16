# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Contributor: Jan Koppe <post@jankoppe.de>

pkgname=yarn
pkgver=1.22.19
pkgrel=1
pkgdesc='Fast, reliable, and secure dependency management'
arch=(any)
url='https://classic.yarnpkg.com/'
license=('BSD')
depends=('nodejs')
source=("https://github.com/yarnpkg/yarn/releases/download/v$pkgver/yarn-v$pkgver.tar.gz")
sha512sums=('ff4579ab459bb25aa7c0ff75b62acebe576f6084b36aa842971cf250a5d8c6cd3bc9420b22ce63c7f93a0857bc6ef29291db39c3e7a23aab5adfd5a4dd6c5d71')

package() {
  cd yarn-v${pkgver}
  install -dm755  "$pkgdir"/usr/lib/node_modules/yarn
  cp -R * "$pkgdir"/usr/lib/node_modules/yarn

  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarn
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarnpkg

  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -Dm644 README.md "$pkgdir/usr/share/doc/$pkgname/README.md"
}

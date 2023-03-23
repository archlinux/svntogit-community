# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Bruno Galeotti <bgaleotti at gmail dot com>

_name=TypeScript
pkgname=typescript
pkgver=5.0.2
pkgrel=2
pkgdesc="TypeScript is a language for application scale JavaScript development"
arch=('any')
url="http://typescriptlang.org/"
license=('Apache')
depends=('nodejs')
makedepends=('npm' 'rsync')
source=("https://github.com/microsoft/TypeScript/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
b2sums=('85b4847dea5b976a5ab20b232039618e933475b93ec39aee7d9b932a2bc087f828ee239ff273ccce11177eed7bfec3463ec4baabec456782fae8870c179d250f')

prepare() {
  cd $_name-$pkgver
  npm ci
}

build() {
  cd $_name-$pkgver
  npx hereby LKG
}

check() {
  cd $_name-$pkgver
  npm run test
}

package() {
  install -d "$pkgdir"/usr/{bin,lib/node_modules/$pkgname}
  ln -s ../lib/node_modules/$pkgname/bin/{tsc,tsserver} "$pkgdir"/usr/bin

  cd $_name-$pkgver
  rsync -r --exclude .gitattributes README.md SECURITY.md bin lib package.json \
    "$pkgdir"/usr/lib/node_modules/$pkgname
  install -Dt "$pkgdir"/usr/share/licenses/$pkgname ThirdPartyNoticeText.txt
}

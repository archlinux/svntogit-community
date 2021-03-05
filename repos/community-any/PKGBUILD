# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.4.1
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-jaraco' 'python-func-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/v$pkgver.tar.gz")
sha512sums=('40df2dae0f3806203496fa9a1befb9b0346c137b10c95bd0fe3881d16882487e8a5abf60a7d68fbefab1d44072bd89a614af680287efb52c24f7293d90ca6c3c')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd zipp-$pkgver
  python setup.py build
}

check() {
  cd zipp-$pkgver
  python -m unittest discover
}

package() {
  cd zipp-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

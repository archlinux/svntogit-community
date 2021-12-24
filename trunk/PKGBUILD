# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.8.0
pkgrel=1
pkgdesc="Style-preserving TOML library for Python"
url="https://github.com/sdispater/tomlkit"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest'
              'python-yaml')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.tar.gz")
sha512sums=('77b267201021e740d8134d0d5edfbef2cf077adac0b320d80887fdedda3f63f74df1957e8230976f16c80fcc58fd4cfabb195cccf0eda7d6cd29f5f65d362147')

build() {
  cd tomlkit-$pkgver
  python setup.py build
}

check() {
  cd tomlkit-$pkgver
  pytest
}

package() {
  cd tomlkit-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}

# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.9.2
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
sha512sums=('9a5a422ad7f2602d164b486dea816f878791393675a17ae30d10f12b6eed0ca73cbfaac7c359f1a57aea4f734b5ba31ee3bbbb95c521e41ce608eae972c2059b')

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

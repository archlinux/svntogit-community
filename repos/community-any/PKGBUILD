# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=6.0.1
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-setuptools')
checkdepends=('python-pytest' 'mercurial' 'git' 'python-pip' 'python-toml')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('d1925a69cb07e9b29416a275b9fadb009a23c148ace905b2fb220649a6c18e92')
b2sums=('7045eec0c1a43d6c93c94e0b2799f0d000cda509fa0df9ee9a638b95383f07fe430b07c3bf72fdc4809563ac289521976956f728a4b2984921fa31532bb7ed8b')

build() {
  cd $_name-$pkgver
  python setup.py build
  python setup.py egg_info
}

check() {
  cd $_name-$pkgver
  mkdir -p temp
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  python setup.py install --root=temp --optimize=1
  PYTHONPATH="$PWD/temp/$site_packages" pytest
}

package() {
  cd $_name-$pkgver
  python setup.py install --root "$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

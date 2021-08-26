# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=6.1.0
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-setuptools')
checkdepends=('python-pytest' 'mercurial' 'git' 'python-pip' 'python-toml')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('0e9fc7ca3f15657941d352ee2be5901d1606294577213e0f4c26cef20978e819')
b2sums=('b1bdf0c2faa34eb77b378908fcd73670b2f1918552b62b0bd6a0359af00508485ddc91704966e4e862255b3c4e93492210741a60da41a8f09f9cd6c660e1aa8a')

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

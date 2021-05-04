# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=matplotlib-inline
pkgname=python-matplotlib-inline
pkgver=0.1.2
pkgrel=1
pkgdesc='Inline Matplotlib backend for Jupyter'
arch=('any')
url=https://github.com/ipython/matplotlib-inline
license=('BSD')
depends=('python-traitlets')
makedepends=('python-setuptools')
checkdepends=('ipython' 'python-matplotlib')
optdepends=('python-matplotlib')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('f41d5ff73c9f5385775d5c0bc13b424535c8402fe70ea8210f93e11f3683993e')
b2sums=('361941d7454e4a9cc6dc7be6d34e48b2ac73a01db0fc341712708295ba922f4a1d94020f41569ea4c7192b8494ddb1187a43287f721fe4fc806d5d5ab1c5ef6d')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  mkdir -p temp
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  python setup.py install --skip-build --root=temp
  PATH="$PWD/temp/usr/bin:$PATH" PYTHONPATH="$PWD/temp/$sitepackages" python -c 'from matplotlib_inline.backend_inline import show'
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:

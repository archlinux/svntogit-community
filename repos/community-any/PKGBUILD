# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Maintainer: Bruno Pagani <archange@archlinux.org>

_name=matplotlib-inline
pkgname=python-matplotlib-inline
pkgver=0.1.3
pkgrel=3
pkgdesc='Inline Matplotlib backend for Jupyter'
arch=('any')
url=https://github.com/ipython/matplotlib-inline
license=('BSD')
depends=('python-traitlets')
makedepends=('python-setuptools')
checkdepends=('ipython' 'python-matplotlib')
optdepends=('python-matplotlib')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('a04bfba22e0d1395479f866853ec1ee28eea1485c1d69a6faf00dc3e24ff34ee')
b2sums=('9f532fc46064c905ad50f4a6d39579848609790eef08d182a5765140781e87b38706221cab3451581627c73ae4e505afcf9c1a5f324aad5bfbf4441a4f95fd08')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python setup.py install --optimize=1 --skip-build
  test-env/bin/python -c 'from matplotlib_inline.backend_inline import show'
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:

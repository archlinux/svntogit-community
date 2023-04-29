# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Liam Timms <timms5000@gmail.com>
# Contributor: Michel Zou

pkgname=python-nbsphinx
pkgver=0.8.11
pkgrel=2
pkgdesc="Jupyter Notebook Tools for Sphinx"
url="http://nbsphinx.rtfd.org/"
arch=(any)
license=('MIT')
depends=('python-docutils' 'python-jinja' 'jupyter-nbconvert' 'jupyter-nbformat' 'python-sphinx')
makedepends=('python-build' 'python-installer' 'python-wheel' 'python-setuptools-scm')
source=("$pkgname-$pkgver.tar.gz::https://github.com/spatialaudio/nbsphinx/archive/${pkgver}.tar.gz")
b2sums=('fc8ab4b6bab910ad47f262b937ce2d941ca4f43040e3b6f2678b29bd40bd82187c8dcdbb9e1918f5e02066b283b72cd1c8f67d961e6b7267b3d1581b91e96869')

build() {
  cd "${srcdir}"/nbsphinx-$pkgver
  python -m build --wheel --no-isolation
}

package() {
  cd "${srcdir}/nbsphinx-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

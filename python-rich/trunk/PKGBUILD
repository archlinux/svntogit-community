# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
_name=rich
pkgver=5.2.1
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-setuptools')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('f294517c324a3c75c0c0e7fc3c52024e2ef39a1e70c7ebefc2eafec4212f628b6b5d1cf3e51eb1f9c6335ac082aec679276e1e4b51ff7adab9422bb5689103d2')

build() {
  cd rich-${pkgver}
  python3 setup.py build
}

package() {
  cd rich-${pkgver}
  python3 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

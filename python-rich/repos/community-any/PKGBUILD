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
source=("https://files.pythonhosted.org/packages/source/r/rich/rich-${pkgver}.tar.gz")
b2sums=('a9ff2857c4e1174421257c40dbe82419015ec63977b34329525415d509ffa80de868b7562041543946dde1d37ed698ef4de0596f33a42fdc7716a2c1711f81f2')

build() {
  cd rich-${pkgver}
  python3 setup.py build
}

package() {
  cd rich-${pkgver}
  python3 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

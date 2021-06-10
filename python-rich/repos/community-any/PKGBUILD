# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=10.3.0
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-pip' 'python-poetry')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('ddac8f2ed7b3b39e647179cd03cf59994729d7d82bdfad6670284a692871b79f2f6ceb86fae0d47d76401f756c122ebcb5978d241d4a95b4f3d6c54de67132a1')

build() {
  cd rich-${pkgver}
  poetry build --format wheel
}

package() {
  cd rich-${pkgver}
  export PYTHONHASHSEED=0
  PIP_CONFIG_FILE=/dev/null pip install --isolated --root="${pkgdir}" --ignore-installed --no-deps dist/*.whl
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

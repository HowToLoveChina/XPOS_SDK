#ifndef __bmpfile_h__
#define __bmpfile_h__

#ifdef __cplusplus
#define BMP_BEGIN_DECLS extern "C" {
#define BMP_END_DECLS }
#else
#define BMP_BEGIN_DECLS
#define BMP_END_DECLS
#endif

BMP_BEGIN_DECLS

#ifndef bool
typedef int bool;
#endif

#ifndef FALSE
#define FALSE (0)
#define TRUE !FALSE
#endif

#ifndef uint8_t
typedef unsigned char uint8_t;
#endif

#ifndef uint16_t
typedef unsigned short uint16_t;
#endif

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

#define TMPFILE_TMP	"tmpfile.bmp"

typedef enum
{
	BI_RGB = 0, //0~��ѹ��
	BI_RLE8, //1~RLE8-ʹ��8λRLEѹ����ʽ
	BI_RLE4, //2~RLE4-ʹ��4λRLEѹ����ʽ
	BI_BITFIELDS, //3~Bitfields-λ���ŷ�ʽ
	BI_JPEG, //
	BI_PNG, //
} bmp_compression_method_t;

typedef struct _rgb_pixel_t
{
	uint8_t blue; //��ɫ
	uint8_t green; //��ɫ
	uint8_t red; //��ɫ
	uint8_t alpha;
} rgb_pixel_t;

typedef struct _bmp_header_t
{
	uint8_t magic[2]; /* �ļ���ʶ, һ��Ϊ��BM���� BM-Windows 3.1x,95,NT; BA-OS/2 Bitmap Array; CI-OS/2 Color Icon; CP-OS/2 Color Pointer; IC-OS/2 Icon; PT-OS/2 Pointer.*/
	uint32_t filesz; /* �ļ���С ��BMP�ļ��Ĵ�С(���ֽ�Ϊ��λ) */
	uint16_t creator1; /* ���� */
	uint16_t creator2; /* ���� */
	uint32_t offset; /* λͼ����ƫ�ơ����ļ���ʼ��λͼ���ݿ�ʼ֮���ƫ����(���ֽ�Ϊ��λ) */
} bmp_header_t;

typedef struct _bmp_dib_v3_header_t
{
	uint32_t header_sz; /* ��Ϣͷ����, ���ֽ�Ϊ��λ. ֵΪ40 */
	uint32_t width; /* λͼ�Ŀ��, ������Ϊ��λ. */
	uint32_t height; /* λͼ�ĸ߶�, ������Ϊ��λ. */
	uint16_t nplanes; /* λͼ������, ����1 */
	uint16_t depth; /* �ֽ�/����. ÿ�����ص�λ��(1~��ɫλͼ, 4~16ɫλͼ, 8~256ɫλͼ, 16~16bit�߲�ɫλͼ, 24~24bit���ɫλͼ, 32~32bit��ǿ�����ɫλͼ) */
	uint32_t compress_type; /* ѹ��˵��:0~��ѹ��, 1~RLE8-ʹ��8λRLEѹ����ʽ, 2~RLE4-ʹ��4λRLEѹ����ʽ, 3~Bitfields-λ���ŷ�ʽ. */
	uint32_t bmp_bytesz; /* λͼ���ݴ�С. ���ֽ�����ʾ��λͼ���ݵĴ�С������������4�ı�����*/
	uint32_t hres; /* ˮƽ�ֱ���. ������/�ױ�ʾ��ˮƽ�ֱ��ʡ�*/
	uint32_t vres; /* ��ֱ�ֱ��ʡ�������/�ױ�ʾ�Ĵ�ֱ�ֱ��ʡ�*/
	uint32_t ncolors; /* ��ɫ����λͼʹ�õ���ɫ����*/
	uint32_t nimpcolors; /* ��Ҫ��ɫ��ָ����Ҫ����ɫ����������ĵ�����ɫ��ʱ(���ߵ���0)����ʾ������ɫ��һ����Ҫ��*/
} bmp_dib_v3_header_t;

typedef struct _bmpfile
{
	bmp_header_t header; //�ļ���Ϣͷ
	bmp_dib_v3_header_t dib;
	rgb_pixel_t **pixels;
	rgb_pixel_t *colors;
} bmpfile_t;

//typedef struct _bmpfile bmpfile_t;

bmpfile_t* bmp_create(uint32_t width, uint32_t height, uint32_t depth);
void bmp_destroy(bmpfile_t *bmp);
bmp_header_t bmp_get_header(bmpfile_t *bmp);
bmp_dib_v3_header_t bmp_get_dib(bmpfile_t *bmp);

uint32_t bmp_get_width(bmpfile_t *bmp);
uint32_t bmp_get_height(bmpfile_t *bmp);
uint32_t bmp_get_depth(bmpfile_t *bmp);

uint32_t bmp_get_dpi_x(bmpfile_t *bmp);
uint32_t bmp_get_dpi_y(bmpfile_t *bmp);
void bmp_set_dpi(bmpfile_t *bmp, uint32_t x, uint32_t y);

rgb_pixel_t* bmp_get_pixel(bmpfile_t *bmp, uint32_t x, uint32_t y);
bool bmp_set_pixel(bmpfile_t *bmp, uint32_t x, uint32_t y, rgb_pixel_t pixel);
bool bmp_save(bmpfile_t *bmp, const char *filename);

BMP_END_DECLS
#endif /* __bmpfile_h__ */
